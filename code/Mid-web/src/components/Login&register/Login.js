import React from "react";
import "./Login.css";
import logo from "./Logo.png";
import "bootstrap/dist/css/bootstrap.min.css";
import "bootstrap/dist/js/bootstrap.bundle.min";
import { useNavigate } from "react-router-dom";

const Login = () => {
  const navigate = useNavigate();
  return (
    <div className="container-fluid">
      <div className="row">
        <div className="col-12 col-md-6 bg_image d-none d-md-block"></div>

        <div className="col-12 col-md-6 form_container d-flex flex-column align-items-center justify-content-center">
          <img src={logo} className="logo mb-4" alt="Decor Dream logo" />

          <input
            className="form-control w-75 mb-3 mx-auto shadow"
            type="text"
            id="contactInfo"
            name="contactInfo"
            placeholder="Enter email or phone number"
            required
          />

          <input
            className="form-control w-75 mb-3 mx-auto"
            type="password"
            placeholder="Password"
            required
          />

          <button className="btn submit gradient-hover-effect w-75 mb-3 mx-auto">
            <b className="h3">Login</b>
          </button>
          <div className="container w-75 mb-3 mx-auto"
            style={{
              height: "100px"
            }}>

            <div className="row">

              <div className="forgot-password text-left col-6" >
                <a href="#">Forgot password?</a>
              </div>
              <div
                className="create-account text-right col-6"
              >
                <a href="./Register">Create new account </a>
              </div></div>

          </div>
        </div>

      </div>
    </div>
  );
};

export default Login;
