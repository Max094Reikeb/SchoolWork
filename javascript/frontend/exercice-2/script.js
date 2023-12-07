const galleryImages = [
    'images/1.jpg',
    'images/2.jpg',
    'images/3.jpg',
    'images/4.jpg',
    'images/5.jpg'
];

const mainImage = document.getElementById('main-img');
const leftChevron = document.getElementById('chevron-left');
const rightChevron = document.getElementById('chevron-right');
const thumbnails = document.querySelectorAll('.thumbnail-row .thumbnail');
let autoChangeInterval = startAutoChange();

function startAutoChange() {
    return setInterval(() => {
        changeImage(1);
    }, 3000);
}

function stopAutoChange() {
    clearInterval(autoChangeInterval);
    autoChangeInterval = startAutoChange();
}

leftChevron.addEventListener('click', function () {
    changeImage(-1);
    stopAutoChange();
});

rightChevron.addEventListener('click', function () {
    changeImage(1);
    stopAutoChange();
});

thumbnails.forEach((thumbnail, index) => {
    thumbnail.addEventListener('click', function () {
        mainImage.src = thumbnail.src;
        mainImage.setAttribute('data-index', index.toString(10));
        stopAutoChange();
    });
});

function changeImage(direction) {
    let currentIndex = parseInt(mainImage.getAttribute('data-index'), 10);
    let newIndex = currentIndex + direction;

    if (newIndex < 0) newIndex = galleryImages.length - 1;
    if (newIndex >= galleryImages.length) newIndex = 0;

    mainImage.src = galleryImages[newIndex];
    mainImage.setAttribute('data-index', newIndex);
}
