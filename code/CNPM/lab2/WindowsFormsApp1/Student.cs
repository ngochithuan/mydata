using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab02
{
    internal class Student
    {
        private string _name;
        private DateTime _bitrh;
        private bool _sex;
        private string _email;

        public Student()
        {
        } 

        public Student(string name, DateTime bitrh, bool sex, string email)
        {
            _name = name;
            _bitrh = bitrh;
            _sex = sex;
            _email = email;
        }

        public string Name { get => _name; set => _name = value; }
        public DateTime Bitrh { get => _bitrh; set => _bitrh = value; }
        public bool Sex { get => _sex; set => _sex = value; }
        public string Email { get => _email; set => _email = value; }

        public string toString() {
            return "["+this._name+", "+this._bitrh + ", " + this._sex + ", " + this._email +"]";
        }
    }
}
