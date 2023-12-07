<script setup>
  import { computed, defineProps } from "vue";
  import ContactForm from './ContactForm.vue';

  const props = defineProps({
    'articles': Array,
    'currentArticleId': Number
  });
  const errorArticle = {
    id: 404,
    title: 'Erreur 404',
    description: '',
    image: '',
    content: 'L\'article que vous cherchez n\'est pas disponible !'
  };
  const article = computed(() => props.articles.find(a => a.id === props.currentArticleId) || errorArticle);
</script>

<template>
  <div class="article-container">
    <h1>{{ article.title }}</h1>
    <p>{{ article.content }}</p>
  </div>
  <ContactForm />
</template>

<style scoped>
  h1 {
    font-size: 32px;
    margin-bottom: 20px;
  }
  .article-container {
    padding: 20px;
  }
</style>
