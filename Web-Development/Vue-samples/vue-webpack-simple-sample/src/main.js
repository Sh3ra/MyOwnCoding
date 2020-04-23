import Vue from 'vue';
import App from './App.vue';
import message from './message.vue';

Vue.component('app-message',message);

new Vue({
  el: '#app',
  render: h => h(App)
});
