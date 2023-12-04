document.getElementById('signin-btn').addEventListener('click', function() {
    showPasswordPage();
});

document.getElementById('password-form').addEventListener('submit', function(event) {
    event.preventDefault(); // Prevent form submission (to handle it with JavaScript)
    validatePassword();
});

document.getElementById('dashboard-btn').addEventListener('click', function() {
    playVideo();
});

function showPasswordPage() {
    var loginContainer = document.getElementById('login-container');
    var passwordContainer = document.getElementById('password-container');
    var usernameInput = document.getElementById('username-input');
    var usernameDisplay = document.getElementById('username-display');

    // Display the password page
    loginContainer.style.display = 'none';
    passwordContainer.style.display = 'block';

    // Set the text content of usernameDisplay to the entered username
    usernameDisplay.textContent = usernameInput.value;
}

function validatePassword() {
    var passwordContainer = document.getElementById('password-container');
    var dashboardContainer = document.getElementById('dashboard-container');

    // Simulate password validation (replace this with your actual validation logic)
    var enteredPassword = document.getElementById('password-input').value;
    if (enteredPassword === 'Deltax21') {
        // Display the dashboard page
        passwordContainer.style.display = 'none';
        dashboardContainer.style.display = 'block';
    } else {
        alert('Invalid password. Please try again.');
        // Clear the password field for a retry
        document.getElementById('password-input').value = '';
    }
}
function playVideo() {
    var videoContainer = document.getElementById('video-container');
    var video = document.createElement('video');
    video.src = 'wish.mp4';
    video.controls = true;
    video.autoplay = true;

    videoContainer.innerHTML = 'Publishing.......'; // Clear any previous video elements
    videoContainer.appendChild(video);
}
