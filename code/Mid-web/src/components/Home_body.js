import React from "react";
import "bootstrap/dist/css/bootstrap.min.css";
import "bootstrap/dist/js/bootstrap.bundle.min";
import homeVideo from "./Home_image/home_video.mp4";

import minimalist from "./Home_image/minimalist.jpg";
import modern from "./Home_image/modern.jpg";
import gaming from "./Home_image/gaming.jpg";
import dark_black from "./Home_image/dark_black.jpg";
import white from "./Home_image/white.jpg";
import nature_wood from "./Home_image/nature_wood.jpg";
import cyberpunk from "./Home_image/cyberpunk.jpg";
import industrial from "./Home_image/industrial.jpg";
const imageMap = {
  minimalist,
  modern,
  gaming,
  dark_black,
  white,
  nature_wood,
  cyberpunk,
  industrial,
};
const Home_body = () => {
  return (
    <section>
      <div className="container col-lg-10 col-xl-10">
        <div className="row">
          <div className="col-12 col-md-12 col-sm-12 col-lg-8 p-3 rounded-lg overflow-hidden">
            <video autoPlay loop muted playsInline style={{ maxWidth: "100%" }}>
              <source src={homeVideo} type="video/mp4" />
              Your browser does not support video.
            </video>
          </div>
          <div className="col-sm-12 col-md-12 col-lg-4 p-1">
            <h1 className="px-3 font-weight-bold">
              Welcome to Decor Dream – Where Your Space Becomes Extraordinary!
            </h1>
            <p>
              We understand that every space has its own story, and our mission
              is to help you create a space that reflects your personal
              touch—from elegant decor pieces to unique setups. Whether you're
              looking for small details to refresh a room or planning to
              transform your entire living space, Decor Dream is the perfect
              destination for those who love creativity and have a passion for
              decoration.
            </p>
          </div>
        </div>
      </div>

      <div className="row">
        <div className="container col-lg-10 col-xl-10">
          <p className="bg-secondary rounded pt-3 pb-3 mb-3 text-white text-center">
            Explore our collection – where carefully curated, high-quality decor
            pieces await, allowing you to freely express your style and
            personality. Don’t just live in a space—create one that is truly
            your own!
          </p>
        </div>
      </div>

      <div className="container col-10 ">
        <div className="row">
          {[
            "minimalist",
            "modern",
            "gaming",
            "dark_black",
            "white",
            "nature_wood",
            "cyberpunk",
            "industrial",
          ].map((style, index) => (
            <div className="col-md-3 col-sm-6 mb-4" key={index}>
              <div className="card h-100"
              >
                <img src={imageMap[style]} alt={style} />
                <div className="card-body">
                  <h5 className="card-title">
                    {style.replace("_", " ").toUpperCase()}
                  </h5>
                  <p className="card-text">Description for {style} setup.</p>
                </div>
                <div className="card-footer text-left">
                  <button
                    type="button"
                    className="btn btn-primary"
                    data-bs-toggle="modal"
                    data-bs-target={`#modal${index + 1}`}
                  >
                    More Info
                  </button>

                  <div
                    className="modal fade"
                    id={`modal${index + 1}`}
                    tabIndex="-1"
                    aria-labelledby={`modalLabel${index + 1}`}
                    aria-hidden="true"
                    style={{
                      background: "rgba(0,0,0,0.5)",
                      // position: "absolute",
                      top: "50%",
                      left: "50%",
                      transform: "translate(-50%, -50%)",
                      width: "100%",
                      height: "100%",
                    }}
                  >
                    <div className="modal-dialog" role="document">
                      <div className="modal-content">
                        <div className="modal-header">
                          <h5
                            className="modal-title"
                            id={`modalLabel${index + 1}`}
                          >
                            {style.replace("_", " ").toUpperCase()}
                          </h5>
                        </div>
                        <div className="modal-body">
                          Content for {style} setup
                        </div>
                        <div className="modal-footer">
                          <button
                            type="button"
                            className="btn btn-secondary"
                            data-bs-dismiss="modal"
                          >
                            Close
                          </button>
                        </div>
                      </div>
                    </div>
                  </div>
                </div>
              </div>
            </div>
          ))}
        </div>
      </div>
    </section >
  );
};

export default Home_body;
