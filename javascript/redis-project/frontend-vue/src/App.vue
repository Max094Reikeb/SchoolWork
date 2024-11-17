<template>
  <div class="container">
    <h1>Entrée de notes</h1>

    <div class="input-section">
      <input v-model="key" class="input-field" placeholder="Entrez un prénom">
      <input v-model="value" class="input-field" placeholder="Entrez une note">
    </div>

    <div class="button-section">
      <button @click="setData" class="button">Enregistrer</button>
      <button @click="getData" class="button">Récupérer</button>
      <button @click="getMoy" class="button">Calculer la moyenne</button>
    </div>


    <div v-if="saveMessage" class="save-message">
      <p :class="saveMessage.type">{{ saveMessage.text }}</p>
    </div>

    <div class="result-section">
      <h2>Résultat :</h2>
      <p v-if="dataFromRedis">{{ dataFromRedis }}</p>
      <p v-else>Aucune donnée trouvée.</p>

      <table v-if="allData.length > 0" class="grades-table">
        <thead>
        <tr>
          <th>Prénom</th>
          <th>Note</th>
          <th>Action</th>
        </tr>
        </thead>
        <tbody>
        <tr v-for="item in allData" :key="item.key">
          <td>{{ item.key }}</td>
          <td>{{ item.value }}</td>
          <td>
            <button @click="deleteData(item.key)" class="delete-button">
              🗑️
            </button>
          </td>
        </tr>
        </tbody>
      </table>
    </div>
  </div>
</template>

<script>
import axios from 'axios';

export default {
  data() {
    return {
      key: '',
      value: '',
      dataFromRedis: '',
      allData: [],
      saveMessage: null
    };
  },
  methods: {
    async setData() {
      try {
        const response = await axios.post('http://localhost:3000/set', {
          key: this.key,
          value: this.value
        });
        console.log(response.data);
        this.saveMessage = {type: 'success', text: 'Les données ont été enregistrées avec succès !'};
        this.dataFromRedis = '';

        setTimeout(() => {
          this.saveMessage = null;
        }, 3000);
      } catch (error) {
        this.saveMessage = {type: 'error', text: 'Erreur lors de l\'enregistrement des données.'};
        console.error('Erreur lors de l\'enregistrement des données:', error);

        setTimeout(() => {
          this.saveMessage = null;
          this.dataFromRedis = 'J\'ai mis longtemps à sauvegarder... Il peut y avoir un problème !';
        }, 5000);
      }
    },

    async getData() {
      try {
        const response = await axios.get(`http://localhost:3000/get/${this.key}`);
        if (response.data.value) {
          this.dataFromRedis = `Clé: ${this.key}, Valeur: ${response.data.value}`;
        } else {
          this.dataFromRedis = response.data.message || 'Aucune valeur trouvée pour cette clé.';
        }
      } catch (error) {
        console.error('Error getting data:', error);
        this.dataFromRedis = 'Erreur lors de l\'obtention des données de Redis.';
      }
    },

    async getMoy() {
      try {
        const response = await axios.get('http://localhost:3000/getAll');
        this.allData = response.data;

        if (this.allData.length > 0) {
          const sum = this.allData.reduce((total, item) => total + parseFloat(item.value), 0);
          const moyenne = (sum / this.allData.length).toFixed(2);
          this.dataFromRedis = `Moyenne des notes : ${moyenne}`;
        } else {
          this.dataFromRedis = '';
        }
      } catch (error) {
        console.error('Error calculating average:', error);
        this.dataFromRedis = 'Erreur lors du calcul de la moyenne.';
      }
    },

    async deleteData(key) {
      try {
        const response = await axios.delete(`http://localhost:3000/delete/${key}`);
        console.log(response.data);

        await this.getMoy();
        this.saveMessage = {type: 'success', text: 'Note supprimée !'};

        setTimeout(() => {
          this.saveMessage = null;
        }, 3000);
      } catch (error) {
        console.error('Erreur lors de la suppression des données:', error);
      }
    }
  }
};
</script>

<style scoped>
.container {
  max-width: 600px;
  margin: 0 auto;
  padding: 20px;
  text-align: center;
  font-family: Arial, sans-serif;
}

.input-section {
  margin-bottom: 20px;
}

.input-field {
  width: 80%;
  padding: 10px;
  margin: 10px 0;
  font-size: 16px;
  border-radius: 5px;
  border: 1px solid #ccc;
}

.button-section {
  margin-bottom: 20px;
}

.button {
  padding: 10px 20px;
  margin: 5px;
  background-color: #28a745;
  color: white;
  border: none;
  border-radius: 5px;
  font-size: 16px;
  cursor: pointer;
}

.button:hover {
  background-color: #218838;
}

.result-section {
  margin-top: 20px;
}

.result-section h2 {
  font-size: 20px;
  margin-bottom: 10px;
}

.result-section p {
  font-size: 18px;
  color: #333;
}

.save-message {
  margin-top: 20px;
}

.save-message p {
  font-size: 16px;
  padding: 10px;
  border-radius: 5px;
}

.save-message p.success {
  background-color: #d4edda;
  color: #155724;
  border: 1px solid #c3e6cb;
}

.save-message p.error {
  background-color: #f8d7da;
  color: #721c24;
  border: 1px solid #f5c6cb;
}

.grades-table {
  width: 100%;
  margin-top: 20px;
  border-collapse: collapse;
}

.grades-table th, .grades-table td {
  border: 1px solid #ddd;
  padding: 8px;
  text-align: center;
}

.grades-table th {
  background-color: #f4f4f4;
}

.delete-button {
  background-color: transparent;
  border: none;
  color: red;
  font-size: 18px;
  cursor: pointer;
}

.delete-button:hover {
  color: darkred;
}
</style>
