import React, { Component } from 'react'

class Counter extends Component {
    constructor(props) {
        super(props)
        this.state = {
             count:0
        }
    }
    inc(){
        this.setState((prevState,props)=>({
            count:prevState.count+props.add
        }))
    }
    incFive(){
        for(let i=0;i<5;i++)
            this.inc();
        // this.inc()
        // this.inc()
        // this.inc()
        // this.inc()
        // this.inc()
    }
    render() {
        const {count}=this.state;
        return (
            <div>
                <h1>Counter -{count}</h1>
                <button onClick={()=>this.incFive()}>Increment</button>
            </div>
        )
    }
}

export default Counter
