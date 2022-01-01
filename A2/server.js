
const http = require('http');
const fs = require("fs");
const pug = require("pug");

const renderStats = pug.compileFile ('stats.pug');

serverItems = [];
const restaurantFolder = './restaurants/';
let fileArray = [];
var restaurants = {};
var orderData = {};
var orderSummary = {};
var averageOrder = {};
var mostPopular = {};
var popularItem = {};

fileArray = fs.readdirSync(restaurantFolder, 'utf8')
fileArray = fileArray.map(i => './restaurants/' + i);
console.log(fileArray);
for (let i = 0; i < fileArray.length; i++){
	let res = require(fileArray[i]);
	restaurants[res.name] = res;
}

function getItemById(id, currentRestaurant){
	let categories = Object.keys(currentRestaurant.menu);
	for(let i = 0; i < categories.length; i++){
		if(currentRestaurant.menu[categories[i]].hasOwnProperty(id)){
			return currentRestaurant.menu[categories[i]][id];
		}
	}
	return null;
}


//creates server and defines route handling
const server = http.createServer(function (request, response) {
	//getting home page
	if(request.method === "GET"){
		if(request.url === "/" || request.url === "/home.html"){
			console.log("Sending home.html");
			//read the orderform.html file and send it back
			fs.readFile("home.html", function(err, data){
				if(err){
					response.statusCode = 500;
					response.write("Server error.");
					response.end();
					return;
				}
				response.statusCode = 200;
				response.setHeader("Content-Type", "text/html");
				response.write(data);
				response.end();
			});
	//getting ordering page
		}else if(request.url === "/orderform.html"){
			console.log("Sending orderform.html");
			//read the home.html file and send it back
			fs.readFile("orderform.html", function(err, data){
				if(err){
					response.statusCode = 500;
					response.write("Server error.");
					response.end();
					return;
				}
				response.statusCode = 200;
				response.setHeader("Content-Type", "text/html");
				response.write(data);
				response.end();
			});
		}else if(request.url === "/client.js"){
			//read todo.js file and send it back
			console.log("Sending client.js");
			fs.readFile("client.js", function(err, data){
				if(err){
					response.statusCode = 500;
					response.write("Server error.");
					response.end();
					return;
				}
				response.statusCode = 200;
				response.setHeader("Content-Type", "application/javascript");
				response.write(data);
				response.end();
			});
			// Using pug to render the stats page
		} else if (request.url.startsWith('/stats')){
			let temp = 0;
			//This calculates the average order amount for each restaurant
			//Prior to calling template engine
			for (const [key, value] of Object.entries(orderSummary)){
				for (let i = 0; i < orderSummary[key].length; i++){
					temp += parseFloat(parseFloat(orderSummary[key][i]).toFixed(2));
				}
				averageOrder[key] = temp/(orderSummary[key].length);
			}
			
			//This calculates the most popular item for each restaurant prior to calling template engine
			//mostPopular is a simply dictionary with key value pairs: [item.name, quantity]
			//We them iterate through this dictionary to find the highest value 
			// and assign that to the popularItem array.
			temp = 0;
			for (const [key, value] of Object.entries(orderData)){
				mostPopular = {};
				for (let i = 0; i < orderData[key].length; i++){
					console.log("This is the data after being parsed: ");
					console.log(JSON.parse(orderData[key][i]));
					for (const [k, v] of Object.entries(JSON.parse(orderData[key][i]))){
						let item = getItemById(k, restaurants[key]);
						mostPopular[item.name] = v;
					}
				}
				popularItem[key] = Object.keys(mostPopular).reduce(function(a, b){ return mostPopular[a] > mostPopular[b] ? a : b });
			}
			console.log(popularItem);

			console.log("This is what is held in averageOrder");
			console.log(averageOrder);
			let data = renderStats({
				'orderData' : JSON.stringify(orderData),
				'orderSummary' : JSON.stringify(orderSummary),
				'averageOrder' : JSON.stringify(averageOrder),
				'popularItem' : JSON.stringify(popularItem),
			});
			response.statusCode = 200;
			response.setHeader('Content-Type', 'text/html');
			response.write(data);
			response.end();
			
		}else if (request.url === '/restaurants'){
			console.log("Sending restaurant info");
			response.write(JSON.stringify(restaurants));
			response.end();

		//Handle images below
		}else if (request.url === '/add.png'){
			fs.readFile("add.png", function(err, data){
				if(err){
					response.statusCode = 500;
					response.write("Error cannot send image");
					response.end();
					return;
				}
				response.statusCode = 200;
				response.setHeader("Content-Type", "image/png");
				response.write(data);
				response.end();
			});
		} else if (request.url === '/remove.png'){
			fs.readFile("remove.png", function(err, data){
				if(err){
					response.statusCode = 500;
					response.write("Error cannot send image");
					response.end();
					return;
				}
				response.statusCode = 200;
				response.setHeader("Content-Type", "image/png");
				response.write(data);
				response.end();
			});
		}else{
			response.statusCode = 404;
			response.write("Unknwn resource.");
			response.end();
		}
	}else if(request.method === "PUT"){
		console.log(request.url);
		//This method populates orderData with [<restaurantID>, <array of dictionaries>]
		// Each array of dictionary uses itemID as a key and quantity as the associated value
		if (request.url.includes('/restaurants/')){

			const paths = request.url.split('/');
			let restaurantID = paths[2];
			restaurantID = restaurantID.replace("%20", " ");
			restaurantID = restaurantID.replace("%20", " ");
			restaurantID = restaurantID.replace("%20", " ");
			let body = "";

			request.on('data', (data) => {
				body += data;
			});

			request.on('end', () => {
				const requestObject = JSON.parse(body);
				console.log(requestObject);
				if (restaurantID in orderData){
					orderData[restaurantID].push(body);
				} else {
					orderData[restaurantID] = [];
					orderData[restaurantID].push(body);
				}
				//IMPORTANT TO CHECK THIS OFTEN BECAUSE USING TEMPLATE ENGINE WILL DEPEND ON WHATS HERE
				console.log("This is what is held in orderData");
				console.log(orderData);
			})
			response.statusCode = 200;
			response.setHeader('Content-Type', 'text/html');
			response.write(JSON.stringify("Put Request OK"));
			response.end();


		}else if (request.url.includes('/orderSummary/')){
			//This method populates orderSummary with [<restaurantID>, <array of int>]
			// Each <array of int> represents the total for a particular order
			const paths = request.url.split('/');
			let restaurantID = paths[2];
			restaurantID = restaurantID.replace("%20", " ");
			restaurantID = restaurantID.replace("%20", " ");
			restaurantID = restaurantID.replace("%20", " ");
			let body = "";

			request.on('data', (data) => {
				body += data;
			});

			request.on('end', () => {
				const requestObject = JSON.parse(body);
				console.log(requestObject);
				if (restaurantID in orderData){
					orderSummary[restaurantID].push(body);
				} else {
					orderSummary[restaurantID] = [];
					orderSummary[restaurantID].push(body);
					averageOrder[restaurantID] = 0;
					popularItem[restaurantID] = "";
				}
				//IMPORTANT TO CHECK THIS OFTEN BECAUSE USING TEMPLATE ENGINE WILL DEPEND ON WHATS HERE
				console.log("This is what is held in orderSummary");
				console.log(orderSummary);
			})
			response.statusCode = 200;
			response.setHeader('Content-Type', 'text/html');
			response.write(JSON.stringify("Put Request OK"));
			response.end();


		}else {
			response.statusCode = 404;
			response.write("Error adding to stats");
			response.end();
		}

	}
});

//Server listens on port 3000
server.listen(3000);
console.log('Server running at http://127.0.0.1:3000/');
