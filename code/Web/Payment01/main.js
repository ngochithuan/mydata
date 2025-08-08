window.onload = () => {
    const BANK_INFO = {
        BANK_ID: "MB",
        ACCOUNT_NO: "0385723976"
    }
    
    const quantity = document.getElementById("quantity");
    const money = document.getElementById("money");
    const btn = document.getElementById("Submit_btn");

    const text_amount = document.getElementById("display_text_amount");
    const text_description = document.getElementById("display_text_description");


    btn.addEventListener('click', buy);
    
    const pay_section = document.getElementById("pay_section");
    const qr_img = document.getElementById("pay_qr");
    

    function buy() {
        pay_section.style.display = "block";

        let pay_amount = (money.value * quantity.value);
        let pay_content = "User_ID Product_ID " + (money.value * quantity.value);
        
        const QR = `https://img.vietqr.io/image/${BANK_INFO.BANK_ID}-${BANK_INFO.ACCOUNT_NO}-qr_only.png?amount=${pay_amount}&addInfo=${pay_content}`
        qr_img.src = QR

        text_amount.innerHTML = pay_amount;
        text_description.innerHTML = pay_content;
    }
    
}
