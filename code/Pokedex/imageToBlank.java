import java.math.*;
import java.awt.*;
import java.awt.image.*;
import java.io.*;

import javax.imageio.ImageIO;
import javax.swing.ImageIcon;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;

public class imageToBlank {
    public static void main(String[] args) {
        try {
            String imagePath = "T:/Code24h/Pokedex/img/mudkip.png/";
            BufferedImage img = ImageIO.read(new File(imagePath));

            JLabel picLabel = new JLabel(new ImageIcon(img));
            JPanel jPanel = new JPanel();
            jPanel.add(picLabel);
            JFrame f = new JFrame();

            int width = img.getWidth();
            int height = img.getHeight();
            Color[][] rgbMatrix = new Color[height][width];
            System.out.println("Res" + width + "x" + height);
            for (int i = 0; i < height; i++) {
                for (int j = 0; j < width; j++) {
                    int color = img.getRGB(j, i);

                    // Components will be in the range of 0..255:
                    int blue = color & 0xff;
                    int green = (color & 0xff00) >> 8;
                    int red = (color & 0xff0000) >> 16;
                    rgbMatrix[i][j] = new Color(red, green, blue);
                }
            }

            // System.out.println(rgbMatrix[230][230].getRed());
            // System.out.println(rgbMatrix[230][230].getGreen());
            // System.out.println(rgbMatrix[230][230].getBlue());

            // System.out.println(rgbMatrix[0][0].getRed());

            // int[][] newImg = new int[height][width];

            // 0.299 ∙ Red + 0.587 ∙ Green + 0.114 ∙ Blue
            BufferedImage newImage = new BufferedImage(height, width, BufferedImage.TYPE_INT_RGB);
            for (int i = 0; i < height; i++) {
                for (int j = 0; j < width; j++) {
                    // int rgb = rgbMatrix[j][i].getRGB();
                    // double R = rgbMatrix[j][i].getRed() / 255.0;
                    // double G = rgbMatrix[j][i].getGreen() / 255.0;
                    // double B = rgbMatrix[j][i].getBlue() / 255.0;

                    // // R = Math.pow(R, 2.4);
                    // // G = Math.pow(G, 2.4);
                    // // B = Math.pow(B, 2.4);
                    // double C_linear = 0.2126 * R + 0.7152 * G + 0.0722 * B;
                    // double C_srgb;
                    // if (C_linear <= 0.0031308) {
                    // C_srgb = 12.92 * C_linear;
                    // } else {
                    // C_srgb = 1.055 * (Math.pow(C_linear, 1 / 2.4) - 0.055);
                    // }
                    // // int rgb = (int) (0.299 * +0.587 * rgbMatrix[j][i].getGreen()
                    // // + 0.114 * rgbMatrix[j][i].getBlue());
                    // Color color = new Color((int) C_srgb);
                    // newImage.setRGB(i, j, color.getRGB());

                    // 80%
                    // int p = rgbMatrix[j][i].getRGB();
                    // int a = (p >> 24) & 0xff;
                    // int r = (p >> 16) & 0xff;
                    // int g = (p >> 8) & 0xff;
                    // int b = p & 0xff;
                    // int avg = (r + g + b) / 3;
                    // p = (a << 24) | (avg << 16) | (avg << 8) | avg;
                    // if (p == -1) {
                    // p = -16777216;
                    // }
                    // newImage.setRGB(i, j, p);

                    // 80%
                    // double GS_RED = 0.299;
                    // double GS_GREEN = 0.587;
                    // double GS_BLUE = 0.114;
                    // int R = rgbMatrix[j][i].getRed();
                    // int G = rgbMatrix[j][i].getGreen();
                    // int B = rgbMatrix[j][i].getBlue();
                    // R = G = B = (int) (GS_RED * R + GS_GREEN * G + GS_BLUE * B);
                    // int color = (new Color(R, G, B).getRGB());
                    // newImage.setRGB(i, j, color);

                    int r = rgbMatrix[j][i].getRed();
                    int g = rgbMatrix[j][i].getGreen();
                    int b = rgbMatrix[j][i].getBlue();
                    int avg = (int) ((r + g + b) / 3);
                    int rgb = (avg << 16) | (avg << 8) | avg;
                    newImage.setRGB(i, j, rgb);
                }
            }
            System.out.println(new Color(0, 0, 0).getRGB());
            String outputPath = "T:/Code24h/Pokedex/img/mudkip_1.png/";
            File ImageFile = new File(outputPath);
            ImageIO.write(newImage, "png", ImageFile);

            f.setSize(new Dimension(img.getWidth() + 30, img.getHeight() + 30));
            f.add(jPanel);
            f.setVisible(true);
        } catch (Exception e) {
            System.out.println("Error");
        }
    }
}