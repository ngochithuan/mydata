let form, addBTN, fNameBox, lNameBox, emailBox;

window.onload = () => {
    form = document.getElementsByTagName('form')[0];
    addBTN = document.getElementsByClassName('btn btn-success px-5 mr-1')[0];
    resetBTN = document.getElementsByClassName('btn btn-outline-primary px-5')[0]

    addBTN.onclick = addHandle;
    resetBTN.onclick = () => {
        fNameBox = document.getElementById('firstname');
        lNameBox = document.getElementById('lastname');
        emailBox = document.getElementById('email');

    }
}

function addHandle(e){
    fNameBox = document.getElementById('firstname');
    lNameBox = document.getElementById('lastname');
    emailBox = document.getElementById('email');

    if (fNameBox.value === ''){
        fNameBox.focus();
        e.preventDefault();
    }
    else if (lNameBox.value === '') {
        lNameBox.focus();
        e.preventDefault();
    }
    else if (emailBox.value == '') {
        emailBox.focus();
        e.preventDefault();
    }

    let txtFName = fNameBox.value;
    let txtLName = lNameBox.value;
    let txtEmail = emailBox.value;

    let student = document.createElement('tr');
    let firstname = document.createElement('td');
    let lastname = document.createElement('td');
    let email = document.createElement('td');
    let deleteBTN = document.createElement('td');

    student.appendChild(firstname);
    student.appendChild(lastname);
    student.appendChild(email);
    student.appendChild(deleteBTN);
    
    firstname.innerHTML = txtFName;
    lastname.innerHTML = txtLName;
    email.innerHTML = txtEmail;
    deleteBTN.innerHTML = '<button class="btn btn-danger btn-sm">Delete</button>';

    let tbody = document.getElementsByTagName('tbody')[0];
    tbody.appendChild(student);
}

