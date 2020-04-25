import React from 'react'

function FunctionClick() {
    function clickHandler(){
        console.log("hehe");
    }
    return (
        <div>
            <button onClick={clickHandler}>FunctionClick</button>
        </div>
    )
}

export default FunctionClick
