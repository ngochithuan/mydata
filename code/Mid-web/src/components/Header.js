import React from "react";
import { NavLink } from "react-router-dom";
import "bootstrap/dist/css/bootstrap.min.css";
import "bootstrap/dist/js/bootstrap.bundle.min";
import logo from "./Logo.png";

export default function Header() {
  return (
    <header
      style={{
        position: "sticky",
        top: 0,
        padding: "10px 16px",
        background: "#555",
        color: "#f1f1f1",
        zIndex: 100,
      }}
      className="bg-dark d-flex"
    >
      <div className="container shadow bg-dark text-white">
        <div className="row w-100">
          {/* Logo Shop - Left side */}
          <div className="logo_container col-lg-1 col-xl-1 col-md-2 col-sm-2 p-3">
            <img src={logo} className="logo_image" alt="Logo" />
          </div>

          {/* Center */}
          <div className="Search_box col-lg-6 col-xl-6 col-md-8 col-sm-8 d-flex container-fluid p-2">
            <input
              className="Search_bar col-lg-10 col-xl-10 col-md-8 col-sm-8 p-2"
              type="text"
              placeholder="Search"
            />
            <button className="Search_button col-lg-2 col-xl-2 col-md-4 col-sm-4 p-2">
              Search
            </button>
          </div>

          {/* Right Side - Navigation */}
          <div className="navbar_container col-lg-5 col-xl-5 col-md-2 col-sm-2 d-flex flex-row-reverse">
            <nav className="navbar navbar-expand-lg navbar-dark bg-dark">
              <div className="container-fluid">
                <button
                  className="navbar-toggler"
                  type="button"
                  data-bs-toggle="collapse"
                  data-bs-target="#navbarNav"
                  aria-controls="navbarNav"
                  aria-expanded="false"
                  aria-label="Toggle navigation"
                >
                  <span className="navbar-toggler-icon"></span>
                </button>

                <div className="collapse navbar-collapse" id="navbarNav">
                  <ul className="navbar-nav ms-auto">
                    <li className="nav-item text-right ">
                      <NavLink className="nav-link" to="/">
                        <b>Home</b>
                      </NavLink>
                    </li>
                    <li className="nav-item text-right">
                      <NavLink className="nav-link" to="/about">
                        <b>About</b>
                      </NavLink>
                    </li>
                    <li className="nav-item text-right">
                      <NavLink className="nav-link" to="/product-category">
                        <b>Services</b>
                      </NavLink>
                    </li>
                    <li className="nav-item text-right">
                      <NavLink className="nav-link" to="/contact">
                        <b>Contact</b>
                      </NavLink>
                    </li>

                    <li className="nav-item text-right">
                      <NavLink className="nav-link" to="/Login">
                        <b>Login</b>
                      </NavLink>
                    </li>
                  </ul>
                </div>
              </div>
            </nav>
          </div>
        </div>
      </div>
    </header>
  );
}
