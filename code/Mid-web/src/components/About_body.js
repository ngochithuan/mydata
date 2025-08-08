import React from "react";

const About_body = () => {
  return (
    <section>
      <div className="container col-lg-10 col-xl-10">
        <div className="row">
          <div className="col-12 col-sm-12 col-lg-12 p-3 rounded-lg overflow-hidden">
            <img
              className="w-100 rounded-top rounded-bottom"
              src="about_image.jpg"
              alt="About Us Image"
            />
          </div>
        </div>
      </div>

      <div className="container col-lg-10 col-xl-10">
        <p className="bg-secondary rounded pt-3 pb-3 mb-3 text-white text-center">
          Hãy khám phá bộ sưu tập của chúng tôi – nơi các sản phẩm decor đẹp mắt
          và chất lượng cao được chọn lọc kỹ càng, giúp bạn thỏa sức thể hiện
          phong cách và cá tính riêng. Đừng chỉ là người sống trong không gian,
          hãy là người tạo dựng nên không gian của chính bạn!
        </p>
      </div>

      <div className="container col-10">
        <div className="row">
          <div className="col-md-6 col-sm-12 col-lg-6 col-xl-6 border rounded p-3">
            <div className="card h-100">
              <div className="card-body">
                <h1>Our Mission</h1>
                <p>
                  At Decor Dream, our mission is to provide quality decor items
                  that help you personalize your space. Whether you are creating
                  a cozy living room or an elegant office, our products are
                  designed to reflect your unique style and preferences.
                </p>
              </div>
              <div className="card-footer text-left">
                <button className="btn btn-primary rounded">Learn More</button>
              </div>
            </div>
          </div>

          <div className="col-md-6 col-sm-12 col-lg-6 col-xl-6 border rounded p-3">
            <div className="card h-100">
              <div className="card-body">
                <h1>Our Values</h1>
                <p>
                  We value creativity, quality, and customer satisfaction. Every
                  item we offer is carefully selected to meet our high
                  standards, ensuring that you receive the best decor for your
                  space. Your satisfaction is our priority!
                </p>
              </div>
              <div className="card-footer text-left">
                <button className="btn btn-primary rounded">
                  Explore Our Values
                </button>
              </div>
            </div>
          </div>
        </div>
      </div>
    </section>
  );
};

export default About_body;
