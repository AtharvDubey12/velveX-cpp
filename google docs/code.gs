function onOpen() {
  DocumentApp.getUi()
    .createMenu('VelveX Tools')
    .addItem('Open Converter', 'showSidebar')
    .addItem('Convert Selected Text', 'convertSelectedTextToLatex')
    .addToUi();
}

function showSidebar() {
  const html = HtmlService.createHtmlOutputFromFile('sidebar')
    .setTitle('VelveX Parser');
  DocumentApp.getUi().showSidebar(html);
}

function convertVelvetToLatex(velvetInput) {
  const url = 'https://velvex.onrender.com/process';
  const options = {
    method: 'post',
    contentType: 'application/json',
    payload: JSON.stringify({ input: velvetInput }),
    muteHttpExceptions: true,
  };
  const response = UrlFetchApp.fetch(url, options);
  return response.getContentText();
}

function convertSelectedTextToLatex() {
  const doc = DocumentApp.getActiveDocument();
  const selection = doc.getSelection();
  if (!selection) {
    DocumentApp.getUi().alert('Please select some text to convert.');
    return;
  }

  const elements = selection.getRangeElements();
  const velvetInput = elements.map(el => {
    const element = el.getElement();
    return element.asText().getText().substring(el.getStartOffset(), el.getEndOffsetInclusive() + 1);
  }).join('');

  const latex = convertVelvetToLatex(velvetInput);

  // Replace the selected text with LaTeX
  elements.forEach(el => {
    const element = el.getElement().asText();
    element.deleteText(el.getStartOffset(), el.getEndOffsetInclusive());
    element.insertText(el.getStartOffset(), latex);
  });
}
