import React from 'react';
//import logo from './logo.svg';
import './App.css';
import Greet from './components/Greet';
import Welcome from './components/Welcome';
import Hello from './components/Hello';
import Message from './components/Message';
import Counter from './components/Counter';
import FunctionClick from './components/FunctionClick';
import ClassClick from './components/ClassClick';
import EventHandler from './components/EventHandler';
function App() {
  return (
    <div className="App">
      <EventHandler/>
      {/* <ClassClick/>
      <FunctionClick/>
      <Counter add={2}/>
      <Message></Message>
      <Greet name="Youssef" adj={"Coolest"}>
        <p>Ramadan Kareem :)</p>
        <p>Ramadan mobark :)</p>
      </Greet>
      <Greet name="Sh3ra" adj={"Smartest"}></Greet>
      <Welcome name="7ambozo"></Welcome>
      <Hello /> */}
    </div>
  );
}

export default App;
