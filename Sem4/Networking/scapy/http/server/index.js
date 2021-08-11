const express = require('express');
const fileupload = require('express-fileupload')
const route = express.Router();
const path = require('path')
const fs = require("fs");
var dateTime = require('node-datetime');


route.use(fileupload());

var options = {
    uri: 'https://api.4chan.org/boards.json',
    json: true,
    headers: {'If-Modified-Since': 'Sun, 06 Oct 2020 01:16:45 GMT'}
  };

route.get('/', (req, res) => {
    return res.sendFile(path.join(__dirname,'static/index.html')) 
});

route.get('/upload', (req, res) => {
    return res.sendFile(path.join(__dirname,'static/upload.html')) 
});

route.get('/success', (req, res) => {
    return res.sendFile(path.join(__dirname,'static/success.html'))
});


// If modified since we are checking from POSTMAN and not from client program
// We send the If-Modified-Since header along with the request header through POSTMAN

route.get('/:id',(req,res) => {
    console.log(req.params.id)
    const file = req.params.id

    var today = new Date();
    var str = today.toGMTString(); 
    
    console.log(str);

    console.log('Got request')
    const if_modified_since = req.get('If-Modified-Since')
    console.log(if_modified_since)

    //var date = new Date(if_modified_since);
    //var ms = Date.parse(if_modified_since);
    //console.log('parsed date: ', date);
    //console.log('parsed date ms: ', ms);
    //console.log('If-Modified-Since: '+date.toUTCString());

    if (fs.existsSync(path.join(__dirname,file))) {
        if(if_modified_since > str){
            console.log('File here')
            return res.sendFile(path.join(__dirname,file))
        }
        else{
            res.status(304).send({'Error' : 'If modified since error'})
        }

    }
    
    res.status(404).send({'Error' : '404 Page Not found'})
    
});

route.post('/upload', (req, res) => {

    console.log(req.files);
    const file_name = req.files.sampleFile.name;
    const data = req.files.sampleFile.data;
    console.log(data)

    if(req.files){

        fs.open(file_name, "w+", (err, fd)=>{
            if(err){
                console.log(err.message);
            }else{
                fs.write(fd, data, (err, bytes)=>{
                    if(err){
                        console.log(err.message);
                    }else{
                        console.log(bytes +' bytes written');
                    }
                })        
            }
        })

        res.redirect('/success')
    }
    else{
        res.status(400).send({'Error' : err})
    }

});

route.post('/:id', (req,res) =>{

    console.log('Got Post request')

    const file = req.params.id;
    const content = req.body.content;
    console.log(content)

    fs.appendFile(file, content, function (err) {
        if (err) {
            return res.status(400).send({'Error' : err})
        }
        console.log('Saved!');
      });

      res.send('Saved!!!')
      
});

route.put('/:id', (req,res) => {

    const file = req.params.id;
    const content = req.body.content;
    console.log(content)

    fs.writeFile(file, content, function (err) {
        if (err) {
            return res.status(400).send({'Error' : err})
        }
        console.log('Updated!');
      });

      res.send('Updated!!!')

});

route.delete('/:id', (req,res) => {

    const file = req.params.id;

    fs.unlink(file, (err) => {
        if (err) {
            res.status(400).send({'Error' : err})
        }
    
        res.send('File Deleted')
        console.log("File is deleted.");
    });


});


module.exports = route