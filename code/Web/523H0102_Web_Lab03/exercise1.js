let form, errorMsg, emailBox, pwdBox;
window.onload = () => {
    errorMsg = document.querySelector('div.errorMessage');
    errorMsg.style.display = 'none';

    form = document.querySelector('form');
    emailBox = document.getElementById('email');
    pwdBox = document.getElementById('pwd');

    form.onsubmit = handleSubmit;
}

function handleSubmit(e){
    if (emailBox.value === ''){
        errorMsg.innerHTML = "Please enter your email address.";
        errorMsg.style.display = 'block';
        e.preventDefault();
    }
    else if (pwdBox.value === ''){
        errorMsg.innerHTML = "Please enter your password address.";
        errorMsg.style.display = 'block';
        pwdBox.focus();
        e.preventDefault();
    }

    e.preventDefault();
}