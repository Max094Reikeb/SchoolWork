const express = require('express');
const bodyParser = require('body-parser');

const app = express();
const port = 5001;


// Simulate traffic
const numRequests = 10; // Number of requests to send
const names = ['Alice', 'Bob', 'Charlie', 'Dave', 'Eve']; // Names to use in the requests

console.log("Hello, World!");

// Use body-parser to parse form data
app.use(bodyParser.urlencoded({ extended: true }));

// Serve static files from the 'public' directory
app.use(express.static('public'));

// Define a route for the home page
app.get('/', (req, res) => {
    res.sendFile(__dirname + '/public/index.html');
});


function handle(request, response) {
    const { name } = request.body;
    response.send(`Hello, ${name}!`);
}


// Handle form submission
app.post('/greet', (req, res) => {
    const { name } = req.body;
    res.send(`Hello, ${name}!`);
    console.log("Start profiling");

    console.profile();
    for (let i = 0; i < numRequests; i++) {
        const randomName = names[Math.floor(Math.random() * names.length)];
        const request = { body: { name: randomName } };
        const response = { send: (message) => console.log(message) }; // Mock response object

        handle(request, response); // Handle the request
    }
    console.profileEnd();
    console.log("End profiling");

});

// Start the server
app.listen(port, () => {
    console.log(`Server is running at http://localhost:${port}`);
});
