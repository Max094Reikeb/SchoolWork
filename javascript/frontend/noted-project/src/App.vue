<script setup>
  import {ref, computed} from 'vue';
  import Home from './views/Home.vue';
  import Article from './components/ArticlePage.vue';

  const routes = {
    '/': Home,
    '/article': Article
  };

  const currentPath = ref(window.location.hash);
  const currentArticleId = ref(0);

  window.addEventListener('hashchange', function () {
    currentPath.value = window.location.hash;
  });

  const currentView = computed(function () {
    let tmpPath = currentPath.value.replace(/\?id=\d/, "");
    return routes[tmpPath.slice(1) || '/'];
  });

  const articles = ref([
    {
      id: 1,
      title: 'Les cultures mondiales',
      description: 'Jettez un coup d\'oeuil aux cultures mondiales',
      image: 'src/assets/images/asia.jpg',
      content: 'Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.'
    },
    {
      id: 2,
      title: 'Les sports extrêmes',
      description: 'Découvrez pourquoi les sports extrêmes vous rendent accros !',
      image: 'src/assets/images/extreme-sport.jpg',
      content: 'Généralement, on utilise un texte en faux latin (le texte ne veut rien dire, il a été modifié), le Lorem ipsum ou Lipsum, qui permet donc de faire office de texte d\'attente. L\'avantage de le mettre en latin est que l\'opérateur sait au premier coup d\'oeil que la page contenant ces lignes n\'est pas valide, et surtout l\'attention du client n\'est pas dérangée par le contenu, il demeure concentré seulement sur l\'aspect graphique.'
    },
    {
      id: 3,
      title: 'Les meilleurs hôtels',
      description: 'Découvrez où passer vos meilleures nuits !',
      image: 'src/assets/images/hotels.jpg',
      content: 'Even though using "lorem ipsum" often arouses curiosity due to its resemblance to classical Latin, it is not intended to have meaning. Where text is visible in a document, people tend to focus on the textual content rather than upon overall presentation, so publishers use lorem ipsum when displaying a typeface or design in order to direct the focus to presentation. "Lorem ipsum" also approximates a typical distribution of spaces in English.'
    },
    {
      id: 4,
      title: 'Les meilleurs sites de vacances',
      description: 'Découvrez où passer vos meilleures vacances !',
      image: 'src/assets/images/vacations.jpg',
      content: 'lorem ipsum（ロレム・イプサム、略してリプサム lipsum ともいう）とは、出版、ウェブデザイン、グラフィックデザインなどの諸分野において使用されている典型的なダミーテキスト。書籍やウェブページや広告などのデザインのプロトタイプを制作したり顧客にプレゼンテーションしたりする際に、まだ正式な文章の出来上がっていないテキスト部分の書体（フォント）、タイポグラフィ、レイアウトなどといった視覚的なデザインを調整したりわかりやすく見せるために用いられる。'
    },
    {
      id: 5,
      title: 'Les meilleurs esprits',
      description: 'Découvrez pourquoi la santé mentale est si importante !',
      image: 'src/assets/images/well-being.jpg',
      content: 'Suspendisse potenti. Vestibulum volutpat. Proin semper, dolor eu porttitor scelerisque, risus dui vehicula justo, id vulputate quam ante vel ipsum. Pellentesque id neque nec ligula elementum aliquet. Maecenas venenatis tortor ut quam faucibus ornare. Donec mollis eros. Mauris magna pede, vehicula eget, molestie ac, vehicula sed, orci. Morbi pharetra urna at eros. Donec cursus dui luctus nulla. Curabitur malesuada justo in libero. In erat diam, sagittis quis, dictum at, ultrices eget, enim. '
    }
  ]);
</script>

<template>
  <h1>Mon Blog</h1>
  <a href="#/">Accueil</a>

  <!-- On rend un lien pour chaque article -->
  <span v-for="article in articles" :key="article.id">
    | <a :href="'#/article?id=' + article.id" @click="currentArticleId = article.id">{{ article.title }}</a>
  </span>

  <!-- On passe les articles pour chaque composant enfant -->
  <component :is="currentView" :articles="articles" :currentArticleId="currentArticleId" :key="currentArticleId"/>
</template>

<style scoped>
h1 {
  padding: 20px;
}

a {
  padding: 20px;
}
</style>
