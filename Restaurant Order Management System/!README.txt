Daniel Yang

Notes for running server:
	Download all the files, navigate to the folder where you've stored them all and run npm start in terminal.

Overall design:

	All orders and derived information (e.g. the total cost of each order) are stored on dictionaries on the server. Data is manipulated server side
	before being sent to template engine. I found that it is much easier to work with the data in javascript than to mess around with the syntax 
	in pug. As a result, all the pug template engine has to do is iterate through each array and output the information.


	
