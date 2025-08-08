window.onload = () => {
    
    window.setInterval(checkPassword, 100)
}

function checkPassword() {
    const pwdField = document.getElementById("pwd");
    let password = pwdField.value;

    const req1 = document.getElementById("req1");
    const req2 = document.getElementById("req2");
    const req3 = document.getElementById("req3");
    const req4 = document.getElementById("req4");

    if (password.length >= 8) {
        req1.classList.remove("alert-danger");
        req1.classList.add("alert-success");
    } else {
        req1.classList.remove("alert-success");
        req1.classList.add("alert-danger");
        
    }

    let isDigit = password.split('').some(char =>
        !isNaN(char) && char !== ' ');

    if (isDigit) {
        req2.classList.remove("alert-danger");
        req2.classList.add("alert-success");
    } else {
        req2.classList.remove("alert-success");
        req2.classList.add("alert-danger");
    }

    
    

    if (password.includes(" ")) {
        req4.classList.remove("alert-danger");
        req4.classList.add("alert-success");
    } else {
        req4.classList.remove("alert-success");
        req4.classList.add("alert-danger");
    }
}