const init = {};

init.load = () => {
    [...document.getElementsByClassName("template")].forEach(e => {
        game.view[e.getAttribute("id")] = e.innerHTML;
    });
    console.log(game.view);
    cards.cards = cards.generecards();
    localStorage.setItem('cartes', cards);
    if (game.order === 'wait') {
        document.getElementById('main').innerHTML = Mustache.render(game.view.register, players)
    } else {
        play.launch();
    }
}
