async function submitInput() {
        const input = document.getElementById('inputBox').value;
        const outputContainer = document.querySelector('.output-container');
        
        // Show loading indicator
        outputContainer.classList.add('loading');
        
        try {
            const res = await fetch('/process', {
                method: 'POST',
                headers: {'Content-Type': 'application/json'},
                body: JSON.stringify({ input })
            });
            const text = await res.text();
            document.getElementById('outputBox').innerText = text;
        } catch (error) {
            document.getElementById('outputBox').innerText = 'Error processing request';
        } finally {
            // Hide loading indicator
            outputContainer.classList.remove('loading');
        }
    }