import React from "react";
import "bootstrap/dist/css/bootstrap.min.css";
import "bootstrap/dist/js/bootstrap.bundle.min";
const Menu = () => {
  return (
    <div className="col-lg-2 col-xl-2 col-sm-12 col-md-12 mb-4 menu">
      <h1
        className="p-1 text-center"
        style={{
          fontSize: "3rem",
          fontWeight: "bold",
          color: "#32383D",
          padding: "1rem",
          textShadow:
            "1px 1px 2px rgba(0, 0, 0, 0.3), -1px -1px 2px rgba(255, 255, 255, 0.8)",
        }}
      >
        <b>Decor Dream</b>
      </h1>

      {menuItems.map((item, index) => (
        <div key={index} className="dropdown show p-2 rounded mb-0">
          <a
            className="btn btn-secondary col-12 dropdown-toggle"
            href="#"
            role="button"
            id={`dropdownMenuLink-${index}`}
            data-bs-toggle="dropdown"
            aria-haspopup="true"
            aria-expanded="false"
          >
            {item.title}
          </a>

          {item.subItems && (
            <div
              className="dropdown-menu"
              aria-labelledby={`dropdownMenuLink-${index}`}
            >
              {item.subItems.map((subItem, subIndex) => (
                <a key={subIndex} className="dropdown-item" href="#">
                  {subItem}
                </a>
              ))}
            </div>
          )}
        </div>
      ))}
    </div>
  );
};

const menuItems = [
  { title: "PC & Laptop", subItems: ["PC", "Laptop"] },
  {
    title: "Linh kiện PC",
    subItems: [
      "CPU",
      "GPU (Card đồ họa)",
      "RAM",
      "SSD & HDD (Ổ cứng)",
      "PSU (Nguồn máy tính)",
      "Bo mạch chủ (Motherboard)",
      "Tản nhiệt (Cooling Solutions)",
    ],
  },
  { title: "Màn hình (Monitors)" },
  {
    title: "Bàn phím cơ & Phụ kiện",
    subItems: ["Action", "Another action", "Something else here"],
  },
  {
    title: "Mice & Mousepads",
    subItems: ["Action", "Another action", "Something else here"],
  },
  {
    title: "Headphones & Speakers",
    subItems: ["Action", "Another action", "Something else here"],
  },
  {
    title: "Gaming Chairs & Desks",
    subItems: ["Action", "Another action", "Something else here"],
  },
  {
    title: "Other Accessories",
    subItems: [
      "Cables & Adapters",
      "Hubs & Docking Stations",
      "LED Lighting",
      "Stands & Mounts",
    ],
  },
];

export default Menu;
