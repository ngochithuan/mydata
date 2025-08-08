import React from "react";
import "bootstrap/dist/css/bootstrap.min.css";
import "bootstrap/dist/js/bootstrap.bundle.min";
const Contact_body = () => {
  return (
    <section className="py-5">
      <div className="container">
        <h2 className="text-center mb-4">Drop us a message</h2>
        <div className="row">
          <div className="col-lg-6">
            <div className="contact-form shadow p-4">
              <h2 className="text-center mb-3">Contact Us</h2>
              <form>
                <div className="mb-3">
                  <input
                    type="text"
                    className="form-control"
                    placeholder="Full Name"
                    required
                  />
                </div>
                <div className="mb-3">
                  <input
                    type="email"
                    className="form-control"
                    placeholder="Email Address"
                    required
                  />
                </div>
                <div className="mb-3">
                  <input
                    type="text"
                    className="form-control"
                    placeholder="Subject"
                    required
                  />
                </div>
                <div className="mb-3">
                  <textarea
                    className="form-control"
                    rows="5"
                    placeholder="Message"
                    required
                  ></textarea>
                </div>
                <button type="submit" className="btn btn-primary w-100">
                  Send Message
                </button>
              </form>
            </div>
          </div>
          <div className="col-lg-6">
            <div className="map shadow" style={{ height: "100%" }}>
              <iframe
                src="https://www.google.com/maps/embed/v1/place?key=YOUR_API_KEY&q=New+York"
                allowFullScreen
                title="Google Map"
                style={{ width: "100%", height: "100%", border: "0" }}
              ></iframe>
            </div>
          </div>
        </div>
        <div className="footer text-center mt-4 p-3 bg-light">
          <p>
            <strong>Address:</strong> 198 West 21th Street, Suite 721 New York
            NY 10016
          </p>
          <p>
            <strong>Phone:</strong> +1235 2355 98
          </p>
          <p>
            <strong>Email:</strong> info@yoursite.com
          </p>
          <p>
            <strong>Website:</strong> yoursite.com
          </p>
        </div>
      </div>
    </section>
  );
};

export default Contact_body;
