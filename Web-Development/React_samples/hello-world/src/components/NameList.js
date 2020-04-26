import React from "react";
import Person from "./Person";

function NameList() {
  const Persons = [
    {
      name: "Youssef",
      age: 21,
      adj: "very cool",
    },
    {
      name: "Omar",
      age: 14,
      adj: "very soda3",
    },
    {
      name: "Sh3ra",
      age: 100,
      adj: "Master of Coolness",
    },
  ];
  const PersonsList = Persons.map((person) => {
   return (<Person key={person.name}  person={person} />)
  });
  return <div>{PersonsList}</div>;
}

export default NameList;
