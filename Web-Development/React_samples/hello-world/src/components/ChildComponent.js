import React from 'react'

function ChildComponent(props) {
    return (
        <div>
            <button onClick={()=>props.greetHandler('Mora')}>Child </button>
        </div>
    )
}

export default ChildComponent
