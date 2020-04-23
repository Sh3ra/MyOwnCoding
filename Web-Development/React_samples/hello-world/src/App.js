import React from 'react';
import logo from './logo.svg';
import './App.css';
import Greet from './components/Greet';
import Welcome from './components/Welcome';
import Hello from './components/Hello';

function App() {
  return (
    <div className="App">
      <Greet name="Youssef">
        <p>Ramadan Kareem :)</p>
        <p>Ramadan mobark :)</p>
      </Greet>
      <Greet name="Sh3ra"></Greet>
      <Welcome name="7ambozo"></Welcome>
      <Hello />
    </div>
  );
}

export default App;
