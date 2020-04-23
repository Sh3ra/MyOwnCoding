import React ,{Component} from 'react';

class Message extends Component {
    constructor(){
        super()
        this.state={
            message: 'WebSite'
        }
    }
    changeMessaeg(){
        this.setState({
                message: 'WebApp'
        })
    }
    render(){
        return (
            <div>
                <h1>Welcome to my {this.state.message}</h1>
                <button onClick={()=> this.changeMessaeg()}>NO!</button>
            </div>
            );
    }
}

export default Message;