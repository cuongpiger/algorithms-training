let speech = new SpeechSynthesisUtterance();
speech.text = "How about going to the cinema?";
speech.lang = "en-US";
window.speechSynthesis.speak(speech);