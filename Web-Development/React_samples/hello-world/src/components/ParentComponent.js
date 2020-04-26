import React, { Component } from 'react'
import ChildComponent from './ChildComponent';

class ParentComponent extends Component {
    constructor(props) {
        super(props)
    
        this.state = {
             parentName: 'Darkness'
        }
        this.greeParent=this.greeParent.bind(this);
    }
    greeParent(childName){
        alert(`Hello ${this.state.parentName} my old Friend, My name is ${childName}`);
    }
    render() {
        return (
            <div>
                <ChildComponent greetHandler={this.greeParent}></ChildComponent>
            </div>
        )
    }
}

export default ParentComponent
