package com.example.myapp;

import androidx.appcompat.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    // Load the native library
    static {
        System.loadLibrary("native-lib");
    }

    // Declare the native methods
    public native String encrypt(String input);
    public native String decrypt(String input);

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        EditText inputText = findViewById(R.id.inputText);
        TextView resultText = findViewById(R.id.resultText);
        Button encryptButton = findViewById(R.id.encryptButton);
        Button decryptButton = findViewById(R.id.decryptButton);

        // Set button actions
        encryptButton.setOnClickListener(v -> {
            String message = inputText.getText().toString();
            resultText.setText(encrypt(message));
        });

        decryptButton.setOnClickListener(v -> {
            String message = inputText.getText().toString();
            resultText.setText(decrypt(message));
        });
    }
}
