// Audio Analysis Code
const mic = new p5.AudioIn();
let amplitude;

function setupAudioAnalysis() {
    mic.start();
    amplitude = new p5.Amplitude();
    amplitude.setInput(mic);
}

function analyzeAudio() {
    const volume = amplitude.getLevel();
    const maxAmplitude = 1; // Adjust this value based on the maximum amplitude you want to consider for movement
    const amplitudeValue = map(volume, 0, maxAmplitude, 0, 255);
    moveElement(amplitudeValue);
}

// Movement Logic
function moveElement(amplitude) {
    // Adjust the movement based on the voice amplitude value
    // Implement your movement logic here

    // Example: Move the element vertically based on the amplitude
    const element = document.getElementById('elementId');
    const maxMovement = 100; // Maximum movement in pixels
    const movement = (amplitude / 255) * maxMovement;
    element.style.transform = `translateY(${movement}px)`;
}

// Initialize audio analysis on page load
document.addEventListener('DOMContentLoaded', () => {
    setupAudioAnalysis();
});

// Call analyzeAudio() in a loop to continuously analyze the audio
setInterval(() => {
    analyzeAudio();
}, 100);