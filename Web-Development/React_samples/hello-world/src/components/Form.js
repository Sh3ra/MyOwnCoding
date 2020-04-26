import React, { Component } from "react";

class Form extends Component {
  constructor(props) {
    super(props);

    this.state = {
      email: "",
      commet: "",
      selected: "Omar",
    };
    this.changeValue = this.changeValue.bind(this);
  }
  changeValue(event) {
    this.setState({
      email: event.target.value,
    });
  }
  changeComment = (event) => {
    this.setState({
      commet: event.target.value,
    });
  };
  updateSelected = (event) => {
    this.setState({
      selected: event.target.value,
    });
  };
  handleSubmit = (event) => {
    alert(`${this.state.email} ${this.state.commet} ${this.state.selected}`);
    event.preventDefault();
  };
  render() {
    return (
      <form onSubmit={this.handleSubmit}>
        <label> E - Mail: </label>{" "}
        <input
          type="email"
          value={this.state.email}
          onChange={this.changeValue}
        ></input>{" "}
        <div>
          <label> Comment </label>{" "}
          <textarea
            value={this.state.commet}
            onChange={this.changeComment}
          ></textarea>{" "}
        </div>{" "}
        <div>
          <select value={this.state.selected} onChange={this.updateSelected}>
            <option value="Youssef"> Youssef </option>{" "}
            <option value="Omar"> Omar </option>{" "}
            <option value="Sh3ra"> Sh3ra </option>{" "}
          </select>{" "}
        </div>{" "}
        <button type="submit"> Submit </button>{" "}
      </form>
    );
  }
}

export default Form;
