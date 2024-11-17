import './assets/css/main.css';

import { createApp } from 'vue';
import App from './App.vue';

import { library, config } from '@fortawesome/fontawesome-svg-core';
import { faGithub, faLinkedin } from '@fortawesome/free-brands-svg-icons';
import { faFilePdf } from '@fortawesome/free-solid-svg-icons';
import { FontAwesomeIcon } from '@fortawesome/vue-fontawesome';

import '@fortawesome/fontawesome-svg-core/styles.css';

config.autoAddCss = false;

library.add(faLinkedin, faGithub, faFilePdf);

const app = createApp(App);

// Register FontAwesomeIcon component globally
app.component('font-awesome-icon', FontAwesomeIcon);

app.mount('#app');
