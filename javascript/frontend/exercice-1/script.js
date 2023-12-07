document.addEventListener("DOMContentLoaded", function () {
    const button = document.querySelector('.button-label');

    button.addEventListener('click', updateName);

    function updateName() {
        let name = prompt('Please enter your name:');
        if (name !== '') {
            button.textContent = 'PLAYER 1: ' + name;
        }
    }
});
