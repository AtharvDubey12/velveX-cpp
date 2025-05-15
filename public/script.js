async function submitInput() {
    const input = document.getElementById('inputBox').value;
    const outputContainer = document.querySelector('.output-container');

    outputContainer.classList.add('loading');

    try {
        const res = await fetch('/process', {
            method: 'POST',
            headers: { 'Content-Type': 'application/json' },
            body: JSON.stringify({ input })
        });

        const rawLatex = await res.text();

        // Display raw LaTeX
        document.getElementById('latexBox').innerText = rawLatex;

        // Render math with MathJax
        const wrappedLatex = `\\[ ${rawLatex} \\]`;
        const outputBox = document.getElementById('outputBox');
        outputBox.innerHTML = wrappedLatex;

        if (window.MathJax) {
            MathJax.typesetPromise([outputBox]);
        }

    } catch (error) {
        document.getElementById('outputBox').innerText = 'Error processing request';
        document.getElementById('latexBox').innerText = '';
    } finally {
        outputContainer.classList.remove('loading');
    }
}
