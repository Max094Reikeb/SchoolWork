<template>
  <div class="contact-form">
    <h2>Contact</h2>
    <div class="input-group">
      <div class="name-email-group">
        <input type="text" placeholder="Name" />
        <input type="email" placeholder="Email" />
      </div>
      <textarea placeholder="Message"></textarea>
      <button>Send</button>
    </div>
  </div>
</template>

<style scoped>
  .contact-form {
    background-color: black;
    color: white;
    padding: 20px;
    margin-bottom: 20px;
    display: flex;
    align-items: flex-start;
  }

  h2 {
    font-size: 24px;
    margin-right: 20px;
  }

  .input-group {
    display: flex;
    flex: 1;
    flex-direction: column;
  }

  .name-email-group {
    display: flex;
    flex-direction: row;
  }

  .input-group input, .contact-form textarea {
    width: 100%;
    padding: 10px;
    margin-bottom: 10px;
    border: 2px solid white;
    background-color: transparent;
    color: white;
    flex: 1;
  }

  .contact-form textarea {
    resize: horizontal;
  }

  .contact-form button {
    align-self: flex-end;
    margin-left: auto;
    padding: 10px 20px;
    border: none;
    background-color: white;
    color: black;
    cursor: pointer;
  }

  .contact-form button:hover {
    background-color: #ddd;
  }
</style>
