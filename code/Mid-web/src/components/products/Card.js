import React from "react";
import "bootstrap/dist/css/bootstrap.min.css";
import { Rating } from "react-simple-star-rating";
import { height } from "@fortawesome/free-solid-svg-icons/fa0";

const Card = ({ image, title, price, description }) => {
  const handleRating = (rate) => {
    console.log("Rated:", rate);
  };
  const onPointerEnter = () => console.log("Enter");
  const onPointerLeave = () => console.log("Leave");
  const onPointerMove = (value, index) => console.log(value, index);

  return (
    <div className="col-md-4 col-sm-12 col-lg-4 col-xl-4  ">
      <div className="card">
        <img src={image} className="card-img-top" alt={title} />

        <div className="card-body">
          <h2 className="text-primary">
            <b>{title}</b>
          </h2>
          <h2>
            <b>${price}</b>
          </h2>
          <p>{description}</p>
        </div>
        <div className="card-footer d-flex justify-content-between align-items-center">
          <div className="rating-container">
            <Rating
              onClick={handleRating}
              onPointerEnter={onPointerEnter}
              onPointerLeave={onPointerLeave}
              onPointerMove={onPointerMove}
              size={24}
            />
          </div>
          <button className="btn btn-primary">Buy</button>
        </div>
      </div>
    </div >
  );
};

export default Card;
