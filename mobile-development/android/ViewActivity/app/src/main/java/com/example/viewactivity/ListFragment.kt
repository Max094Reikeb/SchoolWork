package com.example.viewactivity

import android.os.Bundle
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import androidx.core.view.ViewCompat
import androidx.fragment.app.Fragment
import androidx.navigation.findNavController
import androidx.navigation.fragment.FragmentNavigatorExtras
import androidx.recyclerview.widget.LinearLayoutManager
import androidx.recyclerview.widget.RecyclerView

class ListFragment : Fragment() {

    override fun onCreateView(
        inflater: LayoutInflater,
        container: ViewGroup?,
        savedInstanceState: Bundle?
    ): View? {
        return inflater.inflate(
            R.layout.list,
            container,
            false,
        )
    }

    override fun onViewCreated(view: View, savedInstanceState: Bundle?) {
        super.onViewCreated(view, savedInstanceState)

        view.findViewById<RecyclerView>(R.id.list).apply {

            val content = List(1000) { generateFakeProduct() }

            layoutManager = LinearLayoutManager(requireContext())
            adapter = ListAdapter(content, object : OnClickListener {
                override fun onProductClicked(product: Product, image: View) {
                    ViewCompat.setTransitionName(image, "imageTransition")

                    val extras = FragmentNavigatorExtras(image to "imageTransition")
                    val action = ListFragmentDirections.actionListFragment2ToDetailFragment2(
                        product = product
                    )
                    findNavController().navigate(action, extras)
                }
            })
        }
    }
}
