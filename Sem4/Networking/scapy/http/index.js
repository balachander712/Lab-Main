const express = require('express');
const route = express.Router();
const path = require('path')
const fs = require("fs");


route.get('/:id',(req,res) => {
    console.log(req.params.id)
    const file = req.params.id

    if (fs.existsSync(path.join(__dirname,file))) {
        console.log('File here')
        return res.sendFile(path.join(__dirname,file))
    }
    
    res.status(404).send({'Error' : '404 Page Not found'})
    
});

route.post('/:id', (req,res) =>{

    const file = req.params.id;
    const content = req.body.content;
    console.log(content)

    fs.writeFile(file, content, function (err) {
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

    fs.appendFile(file, content, function (err) {
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