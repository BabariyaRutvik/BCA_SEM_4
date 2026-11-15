package Exam;

import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

/*
  58. Bank login: Login form using AWT components (Label, TextField, Button) 
      with event handling (ActionListener) to validate username and password.
*/
public class BankLogin_58 extends Frame implements ActionListener {

    Label lblUser, lblPass, lblStatus;
    TextField txtUser, txtPass;
    Button btnLogin, btnClear;

    public BankLogin_58() {
        setTitle("Bank NetBanking Login");
        setSize(380, 240);
        setLayout(new FlowLayout(FlowLayout.CENTER, 15, 15));

        // Creating AWT components
        lblUser = new Label("Username:");
        txtUser = new TextField(20);

        lblPass = new Label("Password: ");
        txtPass = new TextField(20);
        txtPass.setEchoChar('*'); // Mask password input

        btnLogin = new Button("Login");
        btnClear = new Button("Clear");

        lblStatus = new Label("Enter username (admin) & password (bank123)");
        lblStatus.setForeground(Color.BLUE);

        // Register ActionListeners
        btnLogin.addActionListener(this);
        btnClear.addActionListener(this);

        // Add components to Frame
        add(lblUser);
        add(txtUser);
        add(lblPass);
        add(txtPass);
        add(btnLogin);
        add(btnClear);
        add(lblStatus);

        // Handle window close
        addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e) {
                dispose();
            }
        });

        setLocationRelativeTo(null); // Center window
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == btnLogin) {
            String user = txtUser.getText().trim();
            String pass = txtPass.getText().trim();

            if (user.equals("admin") && pass.equals("bank123")) {
                lblStatus.setText("Login Successful! Welcome, " + user + ".");
                lblStatus.setForeground(new Color(0, 130, 0)); // Green
            } else {
                lblStatus.setText("Invalid Username or Password!");
                lblStatus.setForeground(Color.RED);
            }
        } else if (e.getSource() == btnClear) {
            txtUser.setText("");
            txtPass.setText("");
            lblStatus.setText("Fields cleared.");
            lblStatus.setForeground(Color.BLUE);
        }
    }

    public static void main(String[] args) {
        BankLogin_58 frame = new BankLogin_58();
        frame.setVisible(true);
    }
}
