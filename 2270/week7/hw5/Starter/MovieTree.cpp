#include "MovieTree.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

// Helper function: Create new node using provided args
MovieNode* getMovieNode(int rank, string t, int y, float r) {
    MovieNode* nn = new MovieNode;
    nn->title = t;
    nn->ranking = rank;
    nn->year = y;
    nn->rating = r;
    return nn;
}

MovieTree::MovieTree() {
  root = NULL;
}

void DestructorMovieTreeHelper(MovieNode *node){
  if(node != NULL){
    DestructorMovieTreeHelper(node->left);
    DestructorMovieTreeHelper(node->right);
    delete node;
    node = NULL;
  }
}

MovieTree::~MovieTree() {
  DestructorMovieTreeHelper(root);
}

void printMovieInventoryHelper(MovieNode* node){
  cout << node << endl;
  if(node != NULL){
    printMovieInventoryHelper(node->left);

    cout << "Movie: " << node->title << " (" << node->rating << ")" << endl;

    printMovieInventoryHelper(node->right);
  }
}

void MovieTree::printMovieInventory() {
  if(root == NULL){
    cout << "Tree is Empty. Cannot Print." << endl;
    return;
  }
  
  printMovieInventoryHelper(root);
}

int alphabeticalSorting(string first, string second){
  for(unsigned int i = 0; i < first.length(); i++){
    char firstLet = tolower(first.at(i));
    char secondLet = tolower(second.at(i));
    if(firstLet < secondLet){
      return 1;
    }
    if(firstLet > secondLet){
      return -1;
    }
  }
  return 0;
}

void MovieTree::addMovieNode(int ranking, string title, int year, float rating) {
  MovieNode* mboi = new MovieNode;
  mboi->ranking = ranking;
  mboi->title = title;
  mboi->year = year;
  mboi->rating = rating;

  if(root == NULL){
    root = mboi;
    return;
  }

  MovieNode* current = root;

  while(true){
    if(current == NULL){
      current = mboi;
      // cout << "Added: " << mboi->title << endl;
      return;
    }
    int comparison = alphabeticalSorting(title, current->title);
    if(comparison == 1){
      if(current->left == NULL){
        current->left = mboi;
        return;
      }
      current = current->left;
    }
    if(comparison == -1){
      if(current->right == NULL){
        current->right = mboi;
        return;
      }
      current = current->right;
    }
  }
}

void MovieTree::findMovie(string title) {
  MovieNode* current = root;

  while(true){
    if(current == NULL){
      cout << "Movie not found." << endl;
      return;
    }
    else if(title == current->title){
      cout << "Movie Info:" << endl;
      cout << "==================" << endl;
      cout << "Ranking:" << current->ranking<< endl;
      cout << "Title  :" << current->title<< endl;
      cout << "Year   :" << current->year<< endl;
      cout << "Rating :" << current->rating<< endl;
      return;
    } else if(title < current->title){
      current = current->left;
    } else{
      current = current->right;
    }
    
  }
}

void queryMoviesHelper(MovieNode* node, float rating, int year){
  if(node != NULL){
    if(node->rating >= rating && node->year > year){
      cout<< node->title <<" ("<< node->year <<") "<< node->rating<<endl;
    }

    queryMoviesHelper(node->left, rating, year);

    queryMoviesHelper(node->right, rating, year);
  }
}

void MovieTree::queryMovies(float rating, int year) {
  cout<<"Movies that came out after "<< year <<" with rating at least "<< rating <<":"<<endl;

  if(root == NULL){
    cout<<"Tree is Empty. Cannot query Movies."<<endl;
    return;
  }

  queryMoviesHelper(root, rating, year);
}

float averageRatingHelper(MovieNode*node, int &counter){
  if(node != NULL){
    counter = counter + 1;
    return node->rating + averageRatingHelper(node->left, counter) + averageRatingHelper(node->right, counter);
  }
  return 0;
}

void MovieTree::averageRating() {
  if(root == NULL){
    cout << "Average rating:0.0" << endl;
    return;
  }

  int counter = 0;
  float total = averageRatingHelper(root, counter);
  // cout << total << "<total || counter>" << counter;
  cout << "Average rating:" << total / counter << endl;
}

void printLevelNodesHelper(MovieNode *node, int level, int curLevel){
  if(node != NULL){
    if(curLevel == level){
      cout<<"Movie: "<< node->title <<" ("<< node->rating<<")"<<endl;
      return;
    }
    else{
      printLevelNodesHelper(node->left, level, curLevel + 1);
      printLevelNodesHelper(node->right, level, curLevel + 1);
    }
  }
}

void MovieTree::printLevelNodes(int level) {
  printLevelNodesHelper(root, level, 0);
}
