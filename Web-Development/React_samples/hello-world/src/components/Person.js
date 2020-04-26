import React from 'react'

function Person({person}) {
    return (
        <div>
           <h1> I am {person.name} , I'm {person.age} and I am {person.adj}</h1>
        </div>
    )
}

export default Person
