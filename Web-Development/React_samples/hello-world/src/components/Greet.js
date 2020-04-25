import React from 'react';

// function Greet(){
//     return <h1>Hello Youssef The Coolest</h1>;
// }

const Greet =({name,children,adj}) => {
return (
    <div>
        <h1>Hello {name} The {adj}</h1>
         {children}
    </div>
    );
}

export default Greet;