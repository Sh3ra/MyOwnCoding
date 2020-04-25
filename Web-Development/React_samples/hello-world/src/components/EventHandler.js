import React, { Component } from 'react'

class EventHandler extends Component {
    constructor(props) {
        super(props)
    
        this.state = {
             message:"hello"
        }
        this.handel=this.handel.bind(this);
    }
    handel(){
        this.setState({
            message:"GoodBye:("
        })
    }
    render() {
        const {message}=this.state;
        return (
            <div>
                <h2>{message}</h2>
                <button onClick={this.handel}>AAAAAAH!</button>
            </div>
        )
    }
}

export default EventHandler
