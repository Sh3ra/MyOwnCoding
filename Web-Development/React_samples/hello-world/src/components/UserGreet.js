import React, { Component } from 'react'

class UserGreet extends Component {
    constructor(props) {
        super(props)
    
        this.state = {
             isLoggedIn: false
        }
    }
    
    render() {
        return this.state.isLoggedIn?(
            <div>
                <h1>My Cool Website</h1>
                Welcome COOL XD
            </div>
        ):(
            <div>
                <h1>My Cool Website</h1>
                Welcome UNKOWN -_-
            </div>

        )
        // let element;
        // if(this.state.isLoggedIn)
        // {
        //     element =<div>Welcome COOL :D</div>
        // }
        // else{
        //     element=
        //         <div>
        //             Welcome Unkown -_-
        //         </div>
        // }
        // return (
        //     <div>
        //         <h1>My Cool Website</h1>
        //         {element}
        //     </div>
        // )
    }
}

export default UserGreet
