Daniel Yang
101194970
Assignment 2

Notes for running server:
	1. Code will only work if the restaurants folder contains only .JSON files. Sometimes your OS may add random extra files for example
	the zip file came contained with a DS_STORE file which I had to remove.

	2. In server.js there are multiple times where I remove "%20" and replace them with " ". This was done a fixed amount of times (3) so 
	restaurant names that have more than 3 spaces will not be cleaned properly. I'm not sure if having "%20" in the restaurant names will
	change anything other than make the outputs look a bit messy.

	3. After fiddling with the code for calculating the most popular item, I realized that iteration through the dictionary on line 110 of server.js
	was not working because orderData[key][i] was not parsed correctly. I did not want to have to modify the rest of my code, so I just added the 
	JSON.parse to this one line.

	4. Can run with node server.js or npm start if you are in the A2 folder.

Overall design:

	All orders and derived information (e.g. the total cost of each order) are stored on dictionaries on the server. Data is manipulated server side
	before being sent to template engine. I found that it is much easier to work with the data in javascript than to mess around with the syntax 
	in pug. As a result, all the pug template engine has to do is iterate through each array and output the information.


	