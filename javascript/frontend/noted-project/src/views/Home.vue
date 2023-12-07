<script setup>
  import { defineProps } from 'vue';
  import ArticleCard from '../components/ArticleCard.vue';
  import ContactForm from '../components/ContactForm.vue';

  // On obtient les articles qui sont passés
  const { articles } = defineProps(['articles']);
</script>

<template>
  <div>
    <div class="articles">
      <!-- On utilise les articles pour rendre les cartes composantes -->
      <ArticleCard v-for="article in articles" :key="article.id" :article="article" :article-id="article.id" />
    </div>
    <ContactForm />
  </div>
</template>

<style scoped>
  .articles {
    display: grid;
    grid-template-columns: repeat(5, 1fr);
    gap: 20px;
    margin-bottom: 20px;
    padding: 15px;
  }
</style>
