import React, { Component } from 'react'
import FRinput from './FRinput'

class FRParentinput extends Component {
    constructor(props) {
        super(props)
    
        this.state = {
             
        }
        this.parentRef=React.createRef();
    }
    clickHandler =()=>{
        this.parentRef.current.focus();
    }
    render() {
        return (
            <div>
                <FRinput ref={this.parentRef}></FRinput>
                <button onClick={this.clickHandler}>Focus Input</button>
            </div>
        )
    }
}

export default FRParentinput
