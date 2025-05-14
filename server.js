const express = require('express');
const { execFile } = require('child_process');
const path = require('path');
const app = express();

app.use(express.json());
app.use(express.static(path.join(__dirname, 'public')));

app.post('/process', (req, res) => {
    const userInput = req.body.input;

    // Call the C++ executable
    execFile('./parser.exe', [userInput], (error, stdout, stderr) => {
        if (error) {
            console.error('Execution error:', error);
            res.status(500).send('Error running processor.exe');
            return;
        }
        res.send(stdout);
    });
});

const PORT = 3000;
app.listen(PORT, () => {
    console.log(`Server running at http://localhost:${PORT}`);
});
