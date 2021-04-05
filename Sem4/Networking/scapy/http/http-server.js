const http = require('http');
const express = require('express')
const index = require('./index.js')
const app = express();

const hostname = '127.0.0.1';
const port = 3000;

const server = http.createServer((req, res) => {
  res.statusCode = 200;
  res.setHeader('Content-Type', 'text/plain');
  res.end('Hello World');
});


server.listen(port, hostname, () => {
  console.log(`Server running at http://${hostname}:${port}/`);
});

app.use(express.json())
app.use('/',index)

app.get('/home', (req,res) => {
  res.send({'name':'balachander'})
})


app.listen(port,() => console.log(`Listening on Port ${port}`));