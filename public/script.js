async function submitInput() {
    const input = document.getElementById('inputBox').value;
    const res = await fetch('/process', {
        method: 'POST',
        headers: {'Content-Type': 'application/json'},
        body: JSON.stringify({ input })
    });
    const text = await res.text();
    document.getElementById('outputBox').innerText = text;
}