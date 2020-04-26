import React from 'react'

function InlineStyle() {
    const style={
        color: 'blue',
        fontSize: '50px'
    }
    return (
        <div>
            <h1 style={style}>Inline</h1>
        </div>
    )
}

export default InlineStyle
