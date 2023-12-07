<script setup>
  import { defineProps } from 'vue';

  const props = defineProps(['article']);

  function viewArticle() {
    window.location.hash = `/article?id=${props.article.id}`;
  }
</script>

<template>
  <div class="article-card">
    <img :src="article.image" alt="Article Image" />
    <h3>{{ article.title }}</h3>
    <p>{{ article.description }}</p>
    <button @click="viewArticle">Lire l'article</button>
  </div>
</template>

<style scoped>
    .article-card {
      border: 1px solid #ccc;
      padding: 10px;
      display: flex;
      flex-direction: column;
      align-items: center;
      gap: 10px;
    }

    .article-card img {
      width: 100%;
      height: auto;
      margin-bottom: 10px;
    }

    .article-card h3, .article-card p {
      margin: 0;
      text-align: center;
    }

    .article-card button {
      margin-top: auto;
      padding: 5px 10px;
      background-color: #000;
      color: #fff;
      border: none;
      cursor: pointer;
    }
</style>
